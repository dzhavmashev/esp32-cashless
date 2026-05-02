// Function : FUN_40141600
// Address  : 0x40141600
// Size     : 160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40141600(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,undefined4 param_9,
                 int param_10)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte abStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_401410c4(param_1,0,param_3,param_4,param_5,param_6);
  if (((iVar1 == 0) && (iVar1 = FUN_4014138c(param_1,param_2,param_9,param_10), iVar1 == 0)) &&
     (iVar1 = FUN_4014151c(param_1,abStack_34,param_8), uVar2 = 0, iVar1 == 0)) goto LAB_40141684;
  while( true ) {
    param_10 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    uVar2 = (*(code *)&SUB_40082ec4)();
    do {
      pbVar3 = (byte *)(param_7 + iVar1);
      pbVar4 = abStack_34 + iVar1;
      iVar1 = iVar1 + 1;
      uVar2 = uVar2 | *pbVar3 ^ *pbVar4;
LAB_40141684:
    } while (iVar1 != param_8);
    iVar1 = 0;
    if (uVar2 != 0) {
      (*(code *)&SUB_4008b530)(param_10,0,param_2);
      iVar1 = -0x12;
    }
  }
  return;
}

