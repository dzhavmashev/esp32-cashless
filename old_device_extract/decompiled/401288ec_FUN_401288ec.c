// Function : FUN_401288ec
// Address  : 0x401288ec
// Size     : 257 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401288ec(undefined4 param_1,char *param_2,undefined *param_3,undefined1 *param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char local_65;
  undefined1 *puStack_64;
  undefined *puStack_60;
  undefined1 *puStack_5c;
  char *pcStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  char *pcStack_24;
  
  memw();
  memw();
  pcStack_24 = _DAT_3ffc5708;
  pcVar3 = &local_65;
  local_65 = '\x01';
  memw();
  puStack_64 = auStack_44;
  uStack_54 = 0x20;
  iStack_50 = 0;
  if (param_3 == (undefined *)0x0) goto LAB_401289ad;
  memw();
  puStack_60 = param_3;
  iStack_50 = (*(code *)&SUB_4008c01c)();
  iStack_50 = iStack_50 + 1;
  do {
    uStack_48 = 1;
    memw();
    puStack_5c = param_4;
    pcStack_58 = pcVar3;
    uStack_4c = param_5;
    iVar2 = FUN_401020e4(param_1,param_2,3,&puStack_60,&iStack_50,auStack_44);
    uVar1 = 0xffffffff;
    if (-1 < iVar2) {
      iVar2 = 0;
      do {
        uVar4 = param_7 - iVar2;
        iVar5 = (uVar4 < 0x20) * uVar4 + (uint)(uVar4 >= 0x20) * 0x20;
        memw();
        (*(code *)&SUB_4008b3d0)(param_6 + iVar2,auStack_44,iVar5);
        iVar2 = iVar2 + iVar5;
        if (param_7 == iVar2) {
          FUN_40102884(auStack_44,0x20);
          uVar1 = 0;
          goto LAB_40128994;
        }
        if (*pcVar3 == -1) break;
        *pcVar3 = *pcVar3 + '\x01';
        memw();
        memw();
        iVar5 = FUN_401020e4(param_1,param_2,4,&puStack_64,&uStack_54,auStack_44);
      } while (-1 < iVar5);
      (*(code *)&SUB_4008b530)(param_6,0,param_7);
      FUN_40102884(auStack_44,0x20);
      uVar1 = 0xffffffff;
    }
LAB_40128994:
    param_1 = uVar1;
    pcVar3 = pcStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (pcStack_24 == _DAT_3ffc5708) {
      return;
    }
    iStack_50 = (*(code *)&SUB_40082ec4)();
    param_4 = &DAT_3ffc5708;
    param_5 = param_1;
LAB_401289ad:
    puStack_60 = &DAT_3f42161d;
    memw();
  } while( true );
}

