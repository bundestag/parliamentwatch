# Patches

## UUID module
Problem: Within the module a uuid.feeds.inc file is placed in our project which cannot be found in the original module. To avoid any other problems during Feeds imports and with next updates of the UUID module we add this file as a patch.

Patch: custom-patches/uuid-module-feeds.patch