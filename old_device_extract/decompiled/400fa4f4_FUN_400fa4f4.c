// Function : FUN_400fa4f4
// Address  : 0x400fa4f4
// Size     : 161 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fa4f4(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_48;
  undefined1 uStack_44;
  char cStack_43;
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  memw();
  uVar2 = *(uint *)(param_1 + 100);
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar1 = 0x1101;
  if (uVar2 != 1) goto LAB_400fa528;
  if (param_3 != 0x41) goto LAB_400fa540;
  do {
    memw();
    iVar1 = FUN_400fa000(param_1,param_2,param_4,0xff);
LAB_400fa528:
    while( true ) {
      do {
        param_1 = iVar1;
        param_3 = uStack_24;
        param_2 = _DAT_3ffc5708;
        memw();
        memw();
        if (uStack_24 == _DAT_3ffc5708) {
          return;
        }
        (*(code *)&SUB_40082ec4)();
LAB_400fa540:
        uStack_48 = 0;
        memw();
        iVar1 = FUN_400f9c84(param_1,param_2,param_3,param_4,&uStack_48,&uStack_44,0xff,0xff);
      } while (iVar1 != 0);
      uVar3 = 0;
      if (cStack_43 == 'B') {
        uVar3 = uVar2;
      }
      if ((uVar3 & 0xff) != 0) break;
      uVar3 = 0;
      if (cStack_43 == 'H') {
        uVar3 = uVar2;
      }
      if ((uVar3 & 0xff) != 0) break;
      iVar1 = FUN_400fbaa4(uStack_48,param_2,param_3,param_4,0xff,0xff);
    }
  } while( true );
}

