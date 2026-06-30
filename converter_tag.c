#include<stdio.h>

#define CONVERTFILE_SIZE 683292                     /* 変換前のファイルサイズ */
#define SETFILE_NUM 36                              /* 設定ファイル数 */
#define SETFILENAME_LEN 26                          /* 設定ファイル文字列数 */
#define HEADER_SIZE 128                             /* ヘッダー */
#define CATNUM_SIZE 4                               /* データカテゴリ番号(A5 A5 A5 XX) */
#define ENCKEY1_OFFSET 98                           /* 暗号鍵1のオフセット */
#define ENCKEY2_OFFSET 100                          /* 暗号鍵2のオフセット */
#define ENCKEY3_OFFSET 102                          /* 暗号鍵3のオフセット */
#define DEVICE_BEFORE_SIZE 76                       /* 01:装置設定(変換前) */
#define DEVICE_AFTER_SIZE  76                       /* 01:装置設定(変換後) */
#define DATETIMESYNC_BEFORE_SIZE 8                  /* 03:時刻同期設定(変換前) */
#define DATETIMESYNC_AFTER_SIZE  8                  /* 03:時刻同期設定(変換後) */
#define NETWORK_BEFORE_SIZE 24                      /* 05:ネットワーク通信設定(変換前) */
#define NETWORK_AFTER_SIZE  24                      /* 05:ネットワーク通信設定(変換後) */
#define NETWORK_ARRAY_NUM1  2                       /* 05:ネットワーク通信設定配列数1 */
#define HIGHCOMM_BEFORE_SIZE 16                     /* 06:上位通信設定(変換前) */
#define HIGHCOMM_AFTER_SIZE  16                     /* 06:上位通信設定(変換後) */
#define LOWCOMM_BEFORE_SIZE  16                     /* 07:下位通信設定(変換前) */
#define LOWCOMM_AFTER_SIZE   16                     /* 07:下位通信設定(変換後) */
#define LOWDEVICE_BEFORE_SIZE 9884                  /* 08:下位機器設定(変換前) */
#define LOWDEVICE_AFTER_SIZE  9884                  /* 08:下位機器設定(変換後) */
#define LOWDEVICE_ARRAY_NUM1  31                    /* 08:下位機器設定配列数1 */
#define MD8_BEFORE_SIZE 8                           /* 09:MD8送信器設定(変換前) */
#define MD8_AFTER_SIZE  8                           /* 09:MD8送信器設定(変換後) */
#define MD8_ARRAY_NUM1 60                           /* 09:MD8送信器設定配列数1 */
#define HTTPSERVERCOMM_BEFORE_SIZE 4                /* 0A:HTTPサーバ通信設定(変換前) */
#define HTTPSERVERCOMM_AFTER_SIZE  4                /* 0A:HTTPサーバ通信設定(変換後) */
#define FTPCLIENTCOMM_BEFORE_SIZE 460               /* 0B:FTPクライアント通信設定(変換前) */
#define FTPCLIENTCOMM_AFTER_SIZE  460               /* 0B:FTPクライアント通信設定(変換後) */
#define FTPSERVERCOMM_BEFORE_SIZE 132               /* 0C:FTPサーバ通信設定(変換前) */
#define FTPSERVERCOMM_AFTER_SIZE  132               /* 0C:FTPサーバ通信設定(変換後) */
#define SMTPCLIENTCOMM_BEFORE_SIZE 532              /* 0D:SMTPクライアント通信設定(変換前) */
#define SMTPCLIENTCOMM_AFTER_SIZE  532              /* 0D:SMTPクライアント通信設定(変換後) */
#define SNTPCLIENTCOMM_BEFORE_SIZE 136              /* 0E:SNTPクライアント通信設定(変換前) */
#define SNTPCLIENTCOMM_AFTER_SIZE  136              /* 0E:SNTPクライアント通信設定(変換後) */
#define SNTPSERVERCOMM_BEFORE_SIZE 4                /* 0F:SNTPサーバ通信設定(変換前) */
#define SNTPSERVERCOMM_AFTER_SIZE  4                /* 0F:SNTPサーバ通信設定(変換後) */
#define EMAILCOMM_BEFORE_SIZE 1156                  /* 10:Email通信設定(変換前) */
#define EMAILCOMM_AFTER_SIZE  1156                  /* 10:Email通信設定(変換後) */
#define INPUTDATAEMAILSEND_BEFORE_SIZE 516          /* 11:入力データメール用Email送信設定(変換前) */
#define INPUTDATAEMAILSEND_AFTER_SIZE  516          /* 11:入力データメール用Email送信設定(変換後) */
#define INPUTDATAEMAILSEND_ARRAY_NUM1 8             /* 11:入力データメール用Email送信設定配列数1 */
#define ALERTEMAILSEND_BEFORE_SIZE 520              /* 12:警報メール用Email送信設定(変換前) */
#define ALERTEMAILSEND_AFTER_SIZE  520              /* 12:警報メール用Email送信設定(変換後) */
#define ALERTEMAILSEND_ARRAY_NUM1 8                 /* 12:警報メール用Email送信設定配列数1 */
#define BATTERYVOLEMAILSEND_BEFORE_SIZE 12          /* 13:電池電圧低下メール用Email送信設定(変換前) */
#define BATTERYVOLEMAILSEND_AFTER_SIZE  12          /* 13:電池電圧低下メール用Email送信設定(変換後) */
#define BATTERYVOLEMAILSEND_ARRAY_NUM1 8            /* 13:電池電圧低下メール用Email送信設定配列数1 */
#define DATAINPUT_BEFORE_SIZE 8                     /* 14:データ入力設定(変換前) */
#define DATAINPUT_AFTER_SIZE  8                     /* 14:データ入力設定(変換後) */
#define INPUTCHANNEL_BEFORE_SIZE 528                /* 15:入力チャンネル設定(変換前) */
#define INPUTCHANNEL_AFTER_SIZE  528                /* 15:入力チャンネル設定(変換後) */
#define INPUTCHANNEL_ARRAY_NUM1 500                 /* 15:入力チャンネル設定配列数1 */
#define MARKERTEXT_BEFORE_SIZE 132                  /* 17:マーカテキスト設定(変換前) */
#define MARKERTEXT_AFTER_SIZE  132                  /* 17:マーカテキスト設定(変換後) */
#define MARKERTEXT_ARRAY_NUM1 200                   /* 17:マーカテキスト設定配列数1 */
#define FILE_BEFORE_SIZE 8                          /* 18:ファイル設定(変換前) */
#define FILE_AFTER_SIZE  8                          /* 18:ファイル設定(変換後) */
#define ALARMCONDITION_BEFORE_SIZE 20               /* 19:警報条件設定(変換前) */
#define ALARMCONDITION_AFTER_SIZE  20               /* 19:警報条件設定(変換後) */
#define ALARMCONDITION_ARRAY_NUM1 500               /* 19:警報条件設定配列数1 */
#define ALARMCONDITION_ARRAY_NUM2 4                 /* 19:警報条件設定配列数2 */
#define ALARMDETECT_BEFORE_SIZE 4                   /* 1A:警報設定(変換前) */
#define ALARMDETECT_AFTER_SIZE  4                   /* 1A:警報設定(変換後) */
#define ALARMRELAYOUTPUT_BEFORE_SIZE 12             /* 1B:警報リレー出力先設定(変換前) */
#define ALARMRELAYOUTPUT_AFTER_SIZE  12             /* 1B:警報リレー出力先設定(変換後) */
#define ALARMRELAYOUTPUT_ARRAY_NUM1 10              /* 1B:警報リレー出力先設定配列数1 */
#define ALARMDO_BEFORE_SIZE 4                       /* 1C:警報DO設定(変換前) */
#define ALARMDO_AFTER_SIZE  4                       /* 1C:警報DO設定(変換後) */
#define INTEGRESETCOMMON_BEFORE_SIZE 4              /* 20:積算リセット共通設定(変換前) */
#define INTEGRESETCOMMON_AFTER_SIZE  4              /* 20:積算リセット共通設定(変換後) */
#define INTEGRESETALLCH_BEFORE_SIZE 8               /* 21:全入力チャンネル自動積算リセット設定(変換前) */
#define INTEGRESETALLCH_AFTER_SIZE  8               /* 21:全入力チャンネル自動積算リセット設定(変換後) */
#define INTEGRESETEACHCH_BEFORE_SIZE 8              /* 22:個別入力チャンネル自動積算リセット設定(変換前) */
#define INTEGRESETEACHCH_AFTER_SIZE  8              /* 22:個別入力チャンネル自動積算リセット設定(変換後) */
#define INTEGRESETEACHCH_ARRAY_NUM1 500             /* 22:個別入力チャンネル自動積算リセット設定配列数1 */
#define LOGINCOMMON_BEFORE_SIZE 12                  /* 24:ログイン共通設定(変換前) */
#define LOGINCOMMON_AFTER_SIZE  12                  /* 24:ログイン共通設定(変換後) */
#define AUTHORIZATION_BEFORE_SIZE 280               /* 28:権限付与設定(変換前) */
#define AUTHORIZATION_AFTER_SIZE  280               /* 28:権限付与設定(変換後) */
#define AUTHORIZATION_ARRAY_NUM1 2                  /* 28:権限付与設定配列数1 */
#define AUTHORIZATION_ARRAY_NUM2 10                 /* 28:権限付与設定配列数2 */
#define ELECTRONICSIGNATURE_BEFORE_SIZE 36          /* 29:電子署名設定(変換前) */
#define ELECTRONICSIGNATURE_AFTER_SIZE  36          /* 29:電子署名設定(変換後) */
#define ELECTRONICSIGNATURE_ARRAY_NUM1 4            /* 29:電子署名設定配列数1 */
#define RECGROUP_BEFORE_SIZE 168                    /* 2A:データ記録グループ設定(変換前) */
#define RECGROUP_AFTER_SIZE  168                    /* 2A:データ記録グループ設定(変換後) */
#define RECGROUP_ARRAY_NUM1 10                      /* 2A:データ記録グループ設定配列数1 */
#define GUIBASIC_BEFORE_SIZE 8                      /* 2E:表示基本設定(変換前) */
#define GUIBASIC_AFTER_SIZE  8                      /* 2E:表示基本設定(変換後) */
#define GUISCREEN_BEFORE_SIZE 4                     /* 30:表示画面設定(変換前) */
#define GUISCREEN_AFTER_SIZE  4                     /* 30:表示画面設定(変換後) */
#define GUICHANNEL_BEFORE_SIZE 44                   /* 31:表示チャンネル設定(変換前) */
#define GUICHANNEL_AFTER_SIZE  76                   /* 31:表示チャンネル設定(変換後) */
#define GUICHANNEL_ARRAY_NUM1 500                   /* 31:表示チャンネル設定配列数1 */
#define GUIGROUP_BEFORE_SIZE 116                    /* 32:表示グループ設定(変換前) */
#define GUIGROUP_AFTER_SIZE  116                    /* 32:表示グループ設定(変換後) */
#define GUIGROUP_ARRAY_NUM1 10                      /* 32:表示グループ設定配列数1 */

int convert( FILE* inputFp, FILE* outputFp, int beforeSize, int afterSize, int array1, int array2, int reservePos1, int reservePos2, int writeReserve )
{
    int i, c;
    int writeSize = 0;
    int readSize = beforeSize * array1 * array2 + CATNUM_SIZE;
    
    while( writeSize != readSize && ( c = fgetc( inputFp ) ) != EOF )
    {
        if( fputc( c, outputFp ) == EOF )
        {
            printf("ファイル書き込み失敗\n");
            return -1;
        }
        writeSize++;
        if( writeSize == reservePos1 )
        {
            for( i = 0; i < ( ( afterSize - beforeSize ) / 2 ); i++ )
            {
                if( fputc( writeReserve, outputFp ) == EOF )
                {
                    printf( "ファイル書き込み失敗\n" );
                    return -1;
                }
            }
            reservePos1 += beforeSize;
        }
        else if( writeSize == reservePos2 )
        {
            for( i = 0; i < ( ( afterSize - beforeSize ) / 2 ); i++ )
            {
                if( fputc( writeReserve, outputFp ) == EOF )
                {
                    printf( "ファイル書き込み失敗\n" );
                    return -1;
                }
            }
            reservePos2 += beforeSize;
        }
    }
    
    return 0;
}

void main( int argc, char* argv[] )
{
    FILE *inputFp;
    FILE *outputFp;
    long fileSize;//fpos_t fileSize;
    int c;
    int i;
    int result;
    int writeSize;
    int readSize = 0;
    int reserveValue = 0;
    int reserveSize;
    int encKey1 = 0;
    int encKey2 = 0;
    int encKey3 = 0;
    char reserve = '\0';
    
    /* 変換前カテゴリサイズ */
    int beforeSize[SETFILE_NUM] =
    {   DEVICE_BEFORE_SIZE,                     DATETIMESYNC_BEFORE_SIZE,               NETWORK_BEFORE_SIZE,                HIGHCOMM_BEFORE_SIZE,               LOWCOMM_BEFORE_SIZE,
        LOWDEVICE_BEFORE_SIZE,                  MD8_BEFORE_SIZE,                        HTTPSERVERCOMM_BEFORE_SIZE,         FTPCLIENTCOMM_BEFORE_SIZE,          FTPSERVERCOMM_BEFORE_SIZE,
        SMTPCLIENTCOMM_BEFORE_SIZE,             SNTPCLIENTCOMM_BEFORE_SIZE,             SNTPSERVERCOMM_BEFORE_SIZE,         EMAILCOMM_BEFORE_SIZE,              INPUTDATAEMAILSEND_BEFORE_SIZE,
        ALERTEMAILSEND_BEFORE_SIZE,             BATTERYVOLEMAILSEND_BEFORE_SIZE,        DATAINPUT_BEFORE_SIZE,              INPUTCHANNEL_BEFORE_SIZE,           MARKERTEXT_BEFORE_SIZE,
        FILE_BEFORE_SIZE,                       ALARMCONDITION_BEFORE_SIZE,             ALARMDETECT_BEFORE_SIZE,            ALARMRELAYOUTPUT_BEFORE_SIZE,       ALARMDO_BEFORE_SIZE,
        INTEGRESETCOMMON_BEFORE_SIZE,           INTEGRESETALLCH_BEFORE_SIZE,            INTEGRESETEACHCH_BEFORE_SIZE,       LOGINCOMMON_BEFORE_SIZE,            AUTHORIZATION_BEFORE_SIZE,
        ELECTRONICSIGNATURE_BEFORE_SIZE,        RECGROUP_BEFORE_SIZE,                   GUIBASIC_BEFORE_SIZE,               GUISCREEN_BEFORE_SIZE,              GUICHANNEL_BEFORE_SIZE,
        GUIGROUP_BEFORE_SIZE };
    
    /* 変換後カテゴリサイズ */
    int afterSize[SETFILE_NUM] =
    {   DEVICE_AFTER_SIZE,                      DATETIMESYNC_AFTER_SIZE,                NETWORK_AFTER_SIZE,                 HIGHCOMM_AFTER_SIZE,                LOWCOMM_AFTER_SIZE,
        LOWDEVICE_AFTER_SIZE,                   MD8_AFTER_SIZE,                         HTTPSERVERCOMM_AFTER_SIZE,          FTPCLIENTCOMM_AFTER_SIZE,           FTPSERVERCOMM_AFTER_SIZE,
        SMTPCLIENTCOMM_AFTER_SIZE,              SNTPCLIENTCOMM_AFTER_SIZE,              SNTPSERVERCOMM_AFTER_SIZE,          EMAILCOMM_AFTER_SIZE,               INPUTDATAEMAILSEND_AFTER_SIZE,
        ALERTEMAILSEND_AFTER_SIZE,              BATTERYVOLEMAILSEND_AFTER_SIZE,         DATAINPUT_AFTER_SIZE,               INPUTCHANNEL_AFTER_SIZE,            MARKERTEXT_AFTER_SIZE,
        FILE_AFTER_SIZE,                        ALARMCONDITION_AFTER_SIZE,              ALARMDETECT_AFTER_SIZE,             ALARMRELAYOUTPUT_AFTER_SIZE,        ALARMDO_AFTER_SIZE,
        INTEGRESETCOMMON_AFTER_SIZE,            INTEGRESETALLCH_AFTER_SIZE,             INTEGRESETEACHCH_AFTER_SIZE,        LOGINCOMMON_AFTER_SIZE,             AUTHORIZATION_AFTER_SIZE,
        ELECTRONICSIGNATURE_AFTER_SIZE,         RECGROUP_AFTER_SIZE,                    GUIBASIC_AFTER_SIZE,                GUISCREEN_AFTER_SIZE,               GUICHANNEL_AFTER_SIZE,
        GUIGROUP_AFTER_SIZE };
    
    /* 配列1サイズ */
    int array1[SETFILE_NUM] =
    {   1,                                      1,                                      NETWORK_ARRAY_NUM1,                 1,                                  1,
        LOWDEVICE_ARRAY_NUM1,                   MD8_ARRAY_NUM1,                         1,                                  1,                                  1,
        1,                                      1,                                      1,                                  1,                                  INPUTDATAEMAILSEND_ARRAY_NUM1,
        ALERTEMAILSEND_ARRAY_NUM1,              BATTERYVOLEMAILSEND_ARRAY_NUM1,         1,                                  INPUTCHANNEL_ARRAY_NUM1,            MARKERTEXT_ARRAY_NUM1,
        1,                                      ALARMCONDITION_ARRAY_NUM1,              1,                                  ALARMRELAYOUTPUT_ARRAY_NUM1,        1,
        1,                                      1,                                      INTEGRESETEACHCH_ARRAY_NUM1,        1,                                  AUTHORIZATION_ARRAY_NUM1,
        ELECTRONICSIGNATURE_ARRAY_NUM1,         RECGROUP_ARRAY_NUM1,                    1,                                  1,                                  GUICHANNEL_ARRAY_NUM1,
        GUIGROUP_ARRAY_NUM1 };
    
    /* 配列2サイズ */
    int array2[SETFILE_NUM] =
    {   1,                                      1,                                      1,                                  1,                                  1,
        1,                                      1,                                      1,                                  1,                                  1,
        1,                                      1,                                      1,                                  1,                                  1,
        1,                                      1,                                      1,                                  1,                                  1,
        1,                                      ALARMCONDITION_ARRAY_NUM2,              1,                                  1,                                  1,
        1,                                      1,                                      1,                                  1,                                  AUTHORIZATION_ARRAY_NUM2,
        1,                                      1,                                      1,                                  1,                                  1,
        1 };
    
    /* Reserve位置 */
    int reservePos1[SETFILE_NUM] =
    {   DEVICE_BEFORE_SIZE - 1 + CATNUM_SIZE,               DATETIMESYNC_BEFORE_SIZE - 1 + CATNUM_SIZE,         NETWORK_BEFORE_SIZE - 1 + CATNUM_SIZE,            HIGHCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,           LOWCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,
        LOWDEVICE_BEFORE_SIZE - 8001 + CATNUM_SIZE,         MD8_BEFORE_SIZE - 1 + CATNUM_SIZE,                  HTTPSERVERCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,     FTPCLIENTCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,      FTPSERVERCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,
        SMTPCLIENTCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,       SNTPCLIENTCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,       SNTPSERVERCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,     EMAILCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,          INPUTDATAEMAILSEND_BEFORE_SIZE - 1 + CATNUM_SIZE,
        ALERTEMAILSEND_BEFORE_SIZE - 1 + CATNUM_SIZE,       BATTERYVOLEMAILSEND_BEFORE_SIZE - 1 + CATNUM_SIZE,  DATAINPUT_BEFORE_SIZE - 1 + CATNUM_SIZE,          INPUTCHANNEL_BEFORE_SIZE - 1 + CATNUM_SIZE,       MARKERTEXT_BEFORE_SIZE - 1 + CATNUM_SIZE,
        FILE_BEFORE_SIZE - 1 + CATNUM_SIZE,                 ALARMCONDITION_BEFORE_SIZE - 1 + CATNUM_SIZE,       ALARMDETECT_BEFORE_SIZE - 1 + CATNUM_SIZE,        ALARMRELAYOUTPUT_BEFORE_SIZE - 1 + CATNUM_SIZE,   ALARMDO_BEFORE_SIZE - 1 + CATNUM_SIZE,
        INTEGRESETCOMMON_BEFORE_SIZE - 1 + CATNUM_SIZE,     INTEGRESETALLCH_BEFORE_SIZE - 1 + CATNUM_SIZE,      INTEGRESETEACHCH_BEFORE_SIZE - 1 + CATNUM_SIZE,   LOGINCOMMON_BEFORE_SIZE - 1 + CATNUM_SIZE,        AUTHORIZATION_BEFORE_SIZE - 1 + CATNUM_SIZE,
        ELECTRONICSIGNATURE_BEFORE_SIZE - 1 + CATNUM_SIZE,  RECGROUP_BEFORE_SIZE - 1 + CATNUM_SIZE,             GUIBASIC_BEFORE_SIZE + CATNUM_SIZE,               GUISCREEN_BEFORE_SIZE + CATNUM_SIZE,              16 + CATNUM_SIZE,
        GUIGROUP_BEFORE_SIZE + CATNUM_SIZE };
    
    int reservePos2[SETFILE_NUM] =
    {   DEVICE_BEFORE_SIZE - 1 + CATNUM_SIZE,               DATETIMESYNC_BEFORE_SIZE - 1 + CATNUM_SIZE,         NETWORK_BEFORE_SIZE - 1 + CATNUM_SIZE,            HIGHCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,           LOWCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,
        LOWDEVICE_BEFORE_SIZE - 8001 + CATNUM_SIZE,         MD8_BEFORE_SIZE - 1 + CATNUM_SIZE,                  HTTPSERVERCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,     FTPCLIENTCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,      FTPSERVERCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,
        SMTPCLIENTCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,       SNTPCLIENTCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,       SNTPSERVERCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,     EMAILCOMM_BEFORE_SIZE - 1 + CATNUM_SIZE,          INPUTDATAEMAILSEND_BEFORE_SIZE - 1 + CATNUM_SIZE,
        ALERTEMAILSEND_BEFORE_SIZE - 1 + CATNUM_SIZE,       BATTERYVOLEMAILSEND_BEFORE_SIZE - 1 + CATNUM_SIZE,  DATAINPUT_BEFORE_SIZE - 1 + CATNUM_SIZE,          INPUTCHANNEL_BEFORE_SIZE - 1 + CATNUM_SIZE,       MARKERTEXT_BEFORE_SIZE - 1 + CATNUM_SIZE,
        FILE_BEFORE_SIZE - 1 + CATNUM_SIZE,                 ALARMCONDITION_BEFORE_SIZE - 1 + CATNUM_SIZE,       ALARMDETECT_BEFORE_SIZE - 1 + CATNUM_SIZE,        ALARMRELAYOUTPUT_BEFORE_SIZE - 1 + CATNUM_SIZE,   ALARMDO_BEFORE_SIZE - 1 + CATNUM_SIZE,
        INTEGRESETCOMMON_BEFORE_SIZE - 1 + CATNUM_SIZE,     INTEGRESETALLCH_BEFORE_SIZE - 1 + CATNUM_SIZE,      INTEGRESETEACHCH_BEFORE_SIZE - 1 + CATNUM_SIZE,   LOGINCOMMON_BEFORE_SIZE - 1 + CATNUM_SIZE,        AUTHORIZATION_BEFORE_SIZE - 1 + CATNUM_SIZE,
        ELECTRONICSIGNATURE_BEFORE_SIZE - 1 + CATNUM_SIZE,  RECGROUP_BEFORE_SIZE - 1 + CATNUM_SIZE,             GUIBASIC_BEFORE_SIZE + CATNUM_SIZE,               GUISCREEN_BEFORE_SIZE + CATNUM_SIZE,              32 + CATNUM_SIZE,
        GUIGROUP_BEFORE_SIZE + CATNUM_SIZE };
    
    if( argc < 2 )
    {
        printf( "コンバートするファイルをドラッグ&ドロップしてください。\n" );
        getchar();
        return;
    }
    
    inputFp = fopen( argv[1], "rb" );
    if( inputFp == NULL )
    {
        printf( "変換元ファイルオープン失敗\n" );
        getchar();
        return;
    }
    

if (fileSize != CONVERTFILE_SIZE)
	/* ファイルサイズ取得 */
	fseek(inputFp, 0, SEEK_END);
	fileSize = ftell(inputFp);
	fseek(inputFp, 0, SEEK_SET);
//    /* ファイルサイズ取得 */
//    fseek( inputFp, 0, SEEK_END );
//    fgetpos( inputFp, &fileSize );
    if( fileSize != CONVERTFILE_SIZE )
    {
        printf( "コンバート前のファイルではありません。\n" );
        getchar();
        return;
    }
    fseek( inputFp, 0, SEEK_SET );
    
    /* 変換先ファイルオープン */
    outputFp = fopen( "convert.fps", "wb" );
    if( outputFp == NULL )
    {
        printf( "変換先ファイルオープン失敗\n" );
        fclose( inputFp );
        getchar();
        return;
    }
    
    /* ヘッダー書き込み */
    writeSize = 0;
    readSize = HEADER_SIZE;
    while( writeSize != readSize && ( c = fgetc(inputFp) ) != EOF )
    {
        if( fputc( c, outputFp ) == EOF )
        {
            printf( "ファイル書き込み失敗\n" );
            fclose( inputFp );
            fclose( outputFp );
            return;
        }
        writeSize++;
        /* 暗号鍵取得 */
        if( writeSize == ENCKEY1_OFFSET )
        {
            encKey1 = c;
        }
        else if( writeSize == ENCKEY2_OFFSET )
        {
            encKey2 = c;
        }
        else if( writeSize == ENCKEY3_OFFSET )
        {
            encKey3 = c;
        }
    }
    
    /* Reserveの暗号化(暗号鍵3種の排他的論理和) */
    reserveValue = encKey1 ^ encKey2 ^ encKey3;
    
    /* データカテゴリ書き込み */
    for ( i = 0; i < SETFILE_NUM; i++ )
    {
        result = convert( inputFp, outputFp, beforeSize[i], afterSize[i], array1[i], array2[i], reservePos1[i], reservePos2[i], reserveValue );
        if( result != 0 )
        {
            printf( "コンバートに失敗しました。\n" );
            fclose( inputFp );
            fclose( outputFp );
            return;
        }
    }
    
    fclose( inputFp );
    fclose( outputFp );
    
    printf( "コンバートが完了しました。(convert.fps)\n" );
    
    getchar();
}
