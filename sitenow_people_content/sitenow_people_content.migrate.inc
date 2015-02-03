<?php

/**
 * @file
 * Migration code for SiteNow People content.
 */

/**
 * Implements hook_migrate_api().
 */
function sitenow_people_content_migrate_api() {
  $api = array(
    'api' => 2,
  );
  return $api;
}

// Initial SiteNowArticlesMigration class.
// @TODO: Refactor to abstract common parts into a "SiteNowMigration" class that
// could then be extended by each app.
class SiteNowPeopleMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    // Avoid known line ending issue: drupal.org/node/1705850
    ini_set('auto_detect_line_endings', TRUE);

    $this->description = t('Import SiteNow People nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'sitenow_people_content') . '/import/people.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('people');

    // Bring on the field mappings
    //$this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_people_first_name', 'first_name');
    $this->addFieldMapping('field_people_last_name', 'last_name');

    // Copy an image file, write DB record to files table, and save in Field storage.
    // We map the filename (relative to the source_dir below) to the field itself.
    $this->addFieldMapping('field_person_image', 'image');
    // Here we specify the directory containing the source files.
    $this->addFieldMapping('field_person_image:source_dir')
         ->defaultValue(drupal_get_path('module', 'sitenow_people_content') . "/import");
    // And we map the alt and title values in the database to those on the image.
    $this->addFieldMapping('field_person_image:alt', 'image_alt');
    $this->addFieldMapping('field_person_image:title', 'image_title');

    $this->addFieldMapping('field_person_position', 'position');

    $this->addFieldMapping('field_person_type', 'type');
    $this->addFieldMapping('field_person_type:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_person_type:ignore_case')
         ->defaultValue(TRUE);

    $this->addFieldMapping('field_person_department', 'dept');
    $this->addFieldMapping('field_person_department:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_person_department:ignore_case')
         ->defaultValue(TRUE);

    $this->addFieldMapping('field_person_bio', 'bio');
    $this->addFieldMapping('field_person_bio:format')->defaultValue('filtered_html');;
    $this->addFieldMapping('field_person_phone', 'phone');
    // Waiting for http://drupal.org/node/1010850
    //$this->addFieldMapping('field_person_website', 'website');
    $this->addFieldMapping('field_person_office', 'office');
    // Author mapping. Defaults to user 1.
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  /**
   * Implements migrate::postRollback().
   * use this to delete demo taxonomy terms that were imported
   */
  public function postRollback() {
    parent::postRollback();
    // initialize array of term names
    $types = array('Demo person type 1','Demo person type 2');
    $depts = array('Demo Department 1','Demo Department 2');
    // loop through array of types
    foreach ($types as $type) {
      // get term ids from name
      $terms = taxonomy_get_term_by_name($type, 'person_type');
      // loop through term ids and delete them
      foreach ($terms as $term) {
        taxonomy_term_delete($term->tid);
      }
    }
    // loop through array of depts
    foreach ($depts as $dept) {
      // get term ids from name
      $terms = taxonomy_get_term_by_name($dept, 'sitenow_people_department');
      // loop through term ids and delete them
      foreach ($terms as $term) {
        taxonomy_term_delete($term->tid);
      }
    }
  }

  // Function for the CSV document
  function csvcolumns() {
    // Title", "Path", "Body"
    $columns[0] = array('nid', 'nid');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('first_name', 'First Name');
    $columns[3] = array('last_name', 'Last Name');
    $columns[4] = array('image', 'Image');
    $columns[5] = array('image_alt', 'Image Alt');
    $columns[6] = array('image_title', 'Image title');
    $columns[7] = array('position', 'Position');
    $columns[8] = array('type', 'Person Type');
    $columns[9] = array('dept', 'Person Dept');
    $columns[10] = array('bio', 'Bio');
    $columns[11] = array('phone', 'Phone');
    $columns[12] = array('website', 'Website');
    $columns[13] = array('office', 'Office');

    return $columns;
  }
}
