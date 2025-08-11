proc source_jimhttp {scripts} {
    set save [pwd]
    cd [find jimhttp]
    foreach script $scripts {
	source $script
    }
    cd $save
}
