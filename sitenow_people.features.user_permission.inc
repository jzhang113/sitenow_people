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

  // Exported permission: administer panelizer node people overview.
  $permissions['administer panelizer node people overview'] = array(
    'name' => 'administer panelizer node people overview',
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

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(),
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

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: enter people revision log entry.
  $permissions['enter people revision log entry'] = array(
    'name' => 'enter people revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override people authored by option.
  $permissions['override people authored by option'] = array(
    'name' => 'override people authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override people authored on option.
  $permissions['override people authored on option'] = array(
    'name' => 'override people authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override people promote to front page option.
  $permissions['override people promote to front page option'] = array(
    'name' => 'override people promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override people published option.
  $permissions['override people published option'] = array(
    'name' => 'override people published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override people revision option.
  $permissions['override people revision option'] = array(
    'name' => 'override people revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override people sticky option.
  $permissions['override people sticky option'] = array(
    'name' => 'override people sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  return $permissions;
}
