# Parliamentwatch

## Getting started

1. Install and start [Docker](https://www.docker.com/community-edition)
1. `$ git clone -b develop git@github.com:parliamentwatch/parliamentwatch.git`
1. `$ cd parliamentwatch`
1. `$ curl -f -u root https://backups.parliamentwatch.org/abgeordnetenwatch.de/abgeordnetenwatch.de_latest.sql.gz > provisioning/var/backup/mysql/abgeordnetenwatch.de_latest.sql.gz`
1. Only if you are running Docker for Mac or Docker for Windows: `$ echo "XDEBUG_REMOTE_CONNECT_BACK=0" > .env`
1. `$ docker-compose up -d`
1. Open [http://localhost:8080](http://localhost:8080) in your browser. It may take a while until the site becomes available during the initial loading of the database backup.

## Docker

The local development environment is managed with Docker Compose. It consists of containers for the database, solr, web server, drush and a syslog server. The syslog server handles the Drupal watchdog logs. To start the stack run `docker-compose up -d`. All logs can be viewed with `docker-compose logs`.

In order to populate the database place a backup file downloaded from http://backups.parliamentwatch.org in `provisioning/var/backup/mysql`. All files with extensions .sql and .sql.gz will be loaded if the database is not initialised yet. To forget the current state and populate the database from a backup again run `docker-compose down --volume` and `docker-compose up -d`.

Drush commands can be executed in a command line service container:

    $ docker-compose exec web bash
    # drush sapi-r politician_archive_index
    # drush sapi-i politician_archive_index 0 1000

## Git commit messages

Please follow these [guidelines for commit messages](http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html).

## Coding standards

Please follow the [coding standards](https://www.drupal.org/coding-standards) and the [API documentation and comment standards](https://www.drupal.org/coding-standards/docs) of the Drupal community. 

## Theme assets

Theme assets are managed with Grunt tasks. To build the assets initially run the following commands:

    $ docker-compose exec web bash
    # cd src
    # npm install
    # node_modules/.bin/grunt build

## Translations

Translations for contributed and custom modules are managed with [Localization update](https://drupal.org/project/l10n_update). To update translations for contributed modules update the translations in your development environment with `drush l10n-update` and commit the changes. On the live environment updates will only be sourced from the files in sites/all/translations. Translations for custom modules and themes are all stored in the PO file for PW Globals. To update translations for custom modules and themes:

    $ docker-compose exec web bash
    # drush en potx
    # make general.pot
    # msgmerge -U -N httpdocs/sites/all/translations/pw_globals-<version>.de.po general.pot
    # drush l10n-update-refresh
    # drush l10n-update

When the version of PW Globals changes the PO file needs to be renamed accordingly.
