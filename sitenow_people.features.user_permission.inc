<?php
/**
 * @file
 * sitenow_people.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sitenow_people_user_default_permissions() {
  $permissions = array();

  // Exported permission: access draggableviews.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      0 => 'administrator',
      1 => 'webmaster',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: administer panelizer node people content.
  $permissions['administer panelizer node people content'] = array(
    'name' => 'administer panelizer node people content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node people context.
  $permissions['administer panelizer node people context'] = array(
    'name' => 'administer panelizer node people context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node people defaults.
  $permissions['administer panelizer node people defaults'] = array(
    'name' => 'administer panelizer node people defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node people layout.
  $permissions['administer panelizer node people layout'] = array(
    'name' => 'administer panelizer node people layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node people settings.
  $permissions['administer panelizer node people settings'] = array(
    'name' => 'administer panelizer node people settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: create people content.
  $permissions['create people content'] = array(
    'name' => 'create people content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any people content.
  $permissions['delete any people content'] = array(
    'name' => 'delete any people content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own people content.
  $permissions['delete own people content'] = array(
    'name' => 'delete own people content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any people content.
  $permissions['edit any people content'] = array(
    'name' => 'edit any people content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own people content.
  $permissions['edit own people content'] = array(
    'name' => 'edit own people content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
