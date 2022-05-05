using System;
using System.IO;
using System.Linq;
using System.Windows.Forms;

class test
{
	[STAThread]
	static void Main(string[] args)
	{

		
		//カレントディレクトリ取得
		string var_path = Directory.GetCurrentDirectory();
		
		/*
		Console.WriteLine( "移動フォルダ名を入力してください(なければ作成)" );
		string var_folder = Console.ReadLine();
		//作成フォルダのディレクトリパス作成
		string var_pathymd = Path.Combine(var_path , var_folder);
		//移動先フォルダ作成
		DirectoryInfo var_di = Directory.CreateDirectory(var_folder);
		*/
		
		/*
		Console.WriteLine( "ファイル末尾に入れる文字を入力してください(不要ならEnter)" );
		string var_file = Console.ReadLine();
		//日付取得
		DateTime var_n = DateTime.Now;
		//日付名称変更
		string var_folder = var_n.ToString("yyyyMMdd");
		*/
		
		//対象とする拡張子
		Console.WriteLine( "対象とする拡張子(xlsx、xlsm、jpg、csvなど)" );
		string var_ext1 = Console.ReadLine();
		//対象とする拡張子に.付加
		string var_ext01 = "*." + var_ext1;
		//カレントディレクトリ内のフォルダ名をすべて取得
		string[] var_files = Directory.GetFiles(var_path, var_ext01);
		//新しい拡張子を設定
		Console.WriteLine( "新しい拡張子(xlsx、xlsm、jpg、csvなど)" );
		string var_ext2 = Console.ReadLine();
		//新しい拡張子に.付加
		string var_ext02 = "." + var_ext2;
		
		//カレントディレクトリ内のフォルダ名をすべて取得(パスなし)
		string[] var_nopath = Directory.GetFiles(var_path, var_ext01).Select(x => Path.GetFileName(x)).ToArray();
		//配列を文字列に変換
		string clip = string.Join( "\n", var_nopath );
		//クリップボードにコピー
		Clipboard.SetDataObject( clip, true );
		
		Console.WriteLine( "ファイル確認中..." );
		foreach(string var in var_files)
		{
			/*
			//拡張子取得
			string var_Ext = Path.GetExtension(var);
			*/
			//拡張子なしのファイル名を取得
			string var_Del = Path.GetFileNameWithoutExtension(var);
			//新たなファイル名を作成/絶対Path作成
			var var_New = Path.Combine( var_path , (var_Del + var_ext02) );
			//名前変更を実行
			File.Move( var, var_New );
			
			Console.WriteLine( var );
			Console.WriteLine( var_New );
		}
	}
}
