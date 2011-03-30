  <div id="printout-page">

  <table id="option-table">
    <tr>
      <td id="breastplate-left" rowspan="2">
        <p>&nbsp;</p>
      </td>
      
      <td id="heading" colspan="3">
        <img src="<?php print $logo; ?>" />
        <h1>LiveAndTell</h1>
        www.liveandtell.com
      </td>
      
      <td id="breastplate-right" rowspan="2">
        <p>&nbsp;</p>
      </td>
      
    </tr>
    
    <tr>
      <td id="back-option">
        <a href="http://liveandtell.com/special/lakota/coloring-book">
        <?php print $left_arrow_icon; ?>
        <div><strong>Back</strong></div>
        </a>
      </td>
      
      <td id="print-option">
        <a href="javascript:window.print()"><?php print $printer_icon; ?>
        <div><strong>Print</strong></div>
        </a>
      </td>
      
      <td id="pronunciation-option">
        <p>&nbsp;</p>
        <!--
        <a href="http://liveandtell.com/special/lakota/coloring-book/guide?id=<?php print $nid ?>">Click here for a pronunciation guide</a>
        -->
      </td>
    </tr>
    
  </table>

  <!-- 627 x 812 -->
  <div id="embedded-flash">
    <object width="627" height="812">
    <!-- <param name="movie" value="http://liveandtell.com/v/<?php print $nid ?>?fontFamily=Lakhota Gmigmeya"></param> -->
    <param name="movie" value="http://liveandtell.com/v/<?php print $nid ?>?f=<?php print $nid ?>&fontFamily=Lakhota Gmigmeya"></param>
    <param name="allowFullScreen" value="true"></param>
    <param name="wmode" value="transparent"></param>
    <!-- <embed src="http://liveandtell.com/v/<?php print $nid ?>?fontFamily=Lakhota Gmigmeya" -->
    <embed src="http://liveandtell.com/v/<?php print $nid ?>?f=<?php print $nid ?>&fontFamily=Lakhota Gmigmeya" 
      type="application/x-shockwave-flash" 
      allowfullscreen="true" 
      width="627" 
      height="812"
      wmode="transparent"
    ></embed>
    </object>
  </div>
  
  <div id="printout">
    <?php print $printout; ?>
  </div>
  
</div>