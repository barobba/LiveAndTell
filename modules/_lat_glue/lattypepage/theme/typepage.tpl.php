
<!-- Begin content -->
<div id="lesson-content">

  <!-- Language selection list -->
  <?php if ($languages_used || $languages_unused): ?>    
    <div id="languages">

      <p>Please select a language</p>

      <!-- Languages with Lesson Plan content -->      
      <?php if ($languages_used): ?>
        <div id="language-used" class="language-list">
          <h2>Active languages</h2>
          <?php print $languages_used; ?>
        </div>
      <?php endif; ?>

      <!-- Languages without Lesson Plan content -->            
      <?php if ($languages_unused): ?>
        <div id="language-unused" class="language-list">
          <h2>More languages on LiveAndTell</h2>
          <?php print $languages_unused; ?>
        </div>
      <?php endif; ?>

    </div>
  <?php endif; ?>  <!-- /Languages selection list -->

  <!-- Language creation form -->
  <?php if ($language_form): ?>
    <div id="language-form" >
      <h2>Add your language</h2>
      <div id="language-form-inner">
        <?php print $language_form; ?>
      </div>
    </div>
  <?php endif; ?>  <!-- /Language creation form -->
  
</div>  <!-- /content -->