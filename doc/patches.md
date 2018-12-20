# Patches

## User revision module
Problem: The module does not check in `_user_revision_access()` if the user going to delete the current user revision. When doing so the module does not handle the resetting to the latest user revision which leads to an outdated vid in users table. The user is not editiable or viewable after that.

Patch: custom-patches/user_revision.patch


## UUID module
Problem: Within the module a uuid.feeds.inc file is placed in our project which cannot be found in the original module. To avoid any other problems during Feeds imports and with next updates of the UUID module we add this file as a patch.

Patch: custom-patches/uuid-module-feeds.patch