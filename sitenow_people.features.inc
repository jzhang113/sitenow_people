<?php
/**
 * @file
 * sitenow_people.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sitenow_people_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sitenow_people_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sitenow_people_image_default_styles() {
  $styles = array();

  // Exported image style: people_grid.
  $styles['people_grid'] = array(
    'name' => 'people_grid',
    'label' => 'People Grid',
    'effects' => array(
      19 => array(
        'label' => 'Manual Crop: Reuse cropped style',
        'help' => 'Reuse a crop selection from another Manual Crop enabled image style.',
        'effect callback' => 'manualcrop_reuse_effect',
        'form callback' => 'manualcrop_reuse_form',
        'summary theme' => 'manualcrop_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'crop_selection_rectangle_3-2',
        ),
        'weight' => 0,
      ),
      21 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 333,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: people_table.
  $styles['people_table'] = array(
    'name' => 'people_table',
    'label' => 'People Table',
    'effects' => array(
      28 => array(
        'label' => 'Manual Crop: Reuse cropped style',
        'help' => 'Reuse a crop selection from another Manual Crop enabled image style.',
        'effect callback' => 'manualcrop_reuse_effect',
        'form callback' => 'manualcrop_reuse_form',
        'summary theme' => 'manualcrop_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'crop_selection_rectangle_3-2',
        ),
        'weight' => 0,
      ),
      30 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 67,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sitenow_people_node_info() {
  $items = array(
    'people' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Use the <em>person</em> content type to create a directory of faculty, staff, and students on your site. This is <strong>not</strong> used to give users access to your site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The title will be constructed from the first name and last name fields, e.g. Jane Doe. A middle name or initial can be used after the first name. The photo field will be used as a thumbnail on the <a href="/people">people page</a>. See the <a href="/admin/apps/sitenow/sitenow_people/configure">demo content</a> for an example.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
