git filter-branch -f --env-filter '
if [ "$GIT_AUTHOR_NAME" = "sshpark" ]
then
export GIT_AUTHOR_NAME="sshpark"
export GIT_AUTHOR_EMAIL="huangjiamingwl@icloud.com"
fi
' ref..HEAD

git filter-branch -f --env-filter '
if [ "$GIT_COMMITTER_NAME" = "sshpark" ]
then
export GIT_COMMITTER_NAME="sshpark"
export GIT_COMMITTER_EMAIL="huangjiamingwl@icloud.com"
fi
' ref..HEAD

