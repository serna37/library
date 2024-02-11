# profile
library_root=~/git/library/
snippet_dir=~/.vim/UltiSnips/
trigger_prefix=ww
sp=_

# whitelist
no_del=(
cpp.snippets
cpp.template.snippets
algo.snippets
)

genact -s 5 --exit-after-modules 1 -m botnet
echo "===================================================="
echo " START"
echo "===================================================="

sleep 0.5
echo " >> STEP1. Delete old snippets ( without whitelist )"
cd $snippet_dir
for v in $(\find . -maxdepth 1 -type f ! -name '${no_del[@]}'); do
    rm "$v"
    echo "delete: $v"
done

sleep 0.5
echo " >> STEP2. Generate snippets files for each category"
setopt +o nomatch
cd $library_root
for category in *(/); do
    v="$category.snippets"
    touch $v
    echo "= create: $v"
    echo "bundle processing..."
    cd $category
    for subgroup in *(/N); do
        cd $subgroup
        for sni in *(.N); do
            echo "snippet $trigger_prefix$sp$category$sp$subgroup$sp${sni:r} \"\" b" >> ../../$v
            cat $sni >> ../../$v
            echo "endsnippet" >> ../../$v
        done
        cd ..
    done
    for sni in *(.N); do
        echo "snippet $trigger_prefix$sp$category$sp${sni:r} \"\" b" >> ../$v
        cat $sni >> ../$v
        echo "endsnippet" >> ../$v
    done
    echo "==="
    cd ..
done

sleep 0.5
echo " >> STEP3. Move snippets files for extension root ( $snippet_dir )"
cd $library_root
generated=(*.snippets)
mv *.snippets $snippet_dir

sleep 0.5
echo " >> STEP4. Include snippets in the root file"
cd $snippet_dir
root_sni=cpp.snippets
echo "# generate: $(date '+%Y-%m-%d %H:%M:%S')" > $root_sni
echo "extends cpp.template" >> $root_sni
echo "extends algo" >> $root_sni
for v in $generated; do
    echo "extends ${v:r}" >> $root_sni
done

echo "===================================================="
echo " DONE"
echo "===================================================="
genact -s 3 --exit-after-modules 1 -m bruteforce
cmatrix
