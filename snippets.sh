# profile
library_root=~/git/library/
snippet_dir=~/.vim/UltiSnips/
trigger_prefix=ww
work_dir=__work

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
echo " >> STEP1. DELETE old snippets ( without whitelist )"
cd $snippet_dir
for v in $(\find . -maxdepth 1 -type f ! -name '${no_del[@]}'); do
    rm "$v"
done

sleep 0.5
echo " >> STEP2. GENERATE snippets up to over 200 char"
cd $library_root
files=($(\find . -mindepth 2 -type f -not -path '*/.*'))
mkdir $work_dir
cnt=1
create=$work_dir/$cnt.snippets
touch $create
line=0
for v in $files; do
    l=$(wc -l < $v)
    if [[ $((line + l + 2))  -gt 200 ]] then
        ((cnt++))
        line=0
        create=$work_dir/$cnt.snippets
        touch $create
    fi
    ((line += l + 2))
    # ./aaa/bbb.hpp -> ._aaa_bbb.hpp
    file=${${v}//\//_}
    # _aaa_bbb hpp
    sni=(${(s:.:)file})
    # ww_aaa_bbb
    echo "snippet $trigger_prefix$sni[1] \"\" b" >> $create
    cat $v >> $create
    echo "endsnippet" >> $create
done

sleep 0.5
echo " >> STEP3. Move snippets files for extension root ( $snippet_dir )"
cd $library_root/$work_dir
generated=(*.snippets)
mv *.snippets $snippet_dir
cd $library_root && rm -r $work_dir

sleep 0.5
echo " >> STEP4. Bundle snippets in the root file"
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
