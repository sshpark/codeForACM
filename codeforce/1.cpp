#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <time.h>
#include <string>
#include <set>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define Node pair<int, int> 
#define usernum 7000
#define movienum 200000


class UserBaseCF {
public:
    UserBaseCF() {}

    void test() {
        clock_t start, stop;
        start = clock();
        generate_dataset("/Users/huangjiaming/Downloads/ml-1m/ratings.dat", 7);
        calc_user_sim();
        std::vector<pair<int, double> > v = recommend(23);
        stop = clock();
        printf("推荐给用户 23 的电影:\n");
        printf("电影编号    推荐系数\n");
        for (int i = 0; i < n_rec_movie; i++)
            printf("%7d %lf\n", v[i].first, v[i].second);

        printf("\n总用时: %fs\n", (double)(stop-start)/CLOCKS_PER_SEC);

    }

private:
    vector<Node> trainset[usernum];
    vector<Node> testset[usernum];

    int n_sim_user = 10;    // 相似用户数
    int n_rec_movie = 10;   // 推荐电影数

    set<int> users;
    set<int> movies;
    set<int> movie2user[movienum];

    map<int, double> W[usernum];

protected:
    void generate_dataset(const char* filename, int k) {
        FILE* fp = fopen(filename, "rt");
        int userId, movieId, timestamp;
        double rating;

        int train_len, test_len;

        train_len = test_len = 0;

        srand(time(0));

        while (fscanf(fp, "%d::%d::%lf::%d", &userId, &movieId, &rating, &timestamp) != EOF) {
            if (rand()%10 < k) {
                users.insert(userId);
                movies.insert(movieId);

                // 电影-用户倒排表
                movie2user[movieId].insert(userId);

                trainset[userId].push_back(make_pair(movieId, rating));
                train_len++;
            } else {
                testset[userId].push_back(make_pair(movieId, rating));
                test_len++;
            }
        }

        printf("数据集分割成功...\n");
        printf("训练集大小: %d, 测试集大小: %d\n", train_len, test_len);
        printf("训练集电影数: %lu, 训练集用户数: %lu\n", movies.size(), users.size());

        fclose(fp);
    }

    void calc_user_sim() {

        // for (auto movie : movies) {
        //     printf("%d:", movie);
        //     for (auto i : movie2user[movie]) 
        //         printf("%d ", i);
        //     printf("\n");
        // }

        set<int> C[usernum]; // 两个用户有看过同一部电影
        map<int, int> C_count[usernum]; // 记录两个用户共同看的电影数
        int N[usernum]; // 用户看过的电影数目
        memset(N, 0, sizeof N);

        for (auto movie : movies) {
            for (auto u : movie2user[movie]) {
                N[u]++;
                for (auto v : movie2user[movie]) {
                    if (u == v) continue;
                    C[u].insert(v);
                    C_count[u][v]++;
                }   
            }
        }

        // for (auto i : users) {
        //     printf("%d:", i);
        //     for (auto j : C[i]) {
        //         printf("%d ", j);
        //     }
        //     printf("\n");
        // }

        for (int u = 1; u < usernum; u++) {
            for (auto related_user : C[u]) {
                W[u][related_user] = C_count[u][related_user]*1.0 / sqrt(N[u]*N[related_user]);
                // printf("%d %d %lf\n", u, related_user, W[u][related_user]);
            }
        }
        printf("用户相似度计算完成...\n");
    }


    vector<pair<int, double> > recommend(int userId) {
        int K = 0;

        map<int, double> tmp_rank;
        vector<pair<int, double> > rnk;

        vector<pair<int, double> > k_sim_users;
        set<int> watched_movies;

        for (auto val : trainset[userId])
            watched_movies.insert(val.first);

        for (auto it = W[userId].begin(); it != W[userId].end(); it++) {
            k_sim_users.push_back(make_pair(it->first, it->second));
        }

        sort(k_sim_users.begin(), k_sim_users.end(), 
            [](const pair<int, double> &x, const pair<int, double> &y) -> double {
                return x.second > y.second;
            });


        for (auto it = k_sim_users.begin(); K < n_sim_user && it != k_sim_users.end(); it++) {
            int similar_user = it->first;
            double similarity_factor = it->second;
            for (auto movie : trainset[similar_user]) {
                if (watched_movies.find(movie.first) != watched_movies.end())
                    continue;

                tmp_rank[movie.first] += similarity_factor;
            }
            K++;
        }

        for (auto it : tmp_rank) {
            rnk.push_back(make_pair(it.first, it.second));
        }

        sort(rnk.begin(), rnk.end(), 
            [](const pair<int, double> &x, const pair<int, double> &y) -> double {
                return x.second > y.second;
            });
        printf("推荐列表前 %d 项已生成...\n", n_rec_movie);
        return rnk;

    }

};

int main(int argc, char const *argv[])
{
    UserBaseCF *test = new UserBaseCF();
    test->test();
    return 0;
}