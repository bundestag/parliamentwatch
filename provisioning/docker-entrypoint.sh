#!/bin/bash
set -eo pipefail
shopt -s nullglob

# if command starts with an option, prepend apache2ctl
if [ "${1:0:1}" = "-" ]; then
	set -- apache2ctl "$@"
fi

chmod -R u+w httpdocs/sites/default
cp provisioning/settings.php httpdocs/sites/default/

if [ ! -d src/node_modules ]; then
	cd src
	npm install
	node_modules/.bin/grunt build
	cd -
fi

exec "$@"
