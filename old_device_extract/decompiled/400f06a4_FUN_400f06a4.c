// Function : FUN_400f06a4
// Address  : 0x400f06a4
// Size     : 153 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f06a4(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_a0 [8];
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 *puStack_7c;
  undefined1 *puStack_78;
  undefined4 uStack_74;
  undefined1 *puStack_70;
  undefined1 *puStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [64];
  int iStack_24;
  undefined1 auStack_20 [32];
  
  puStack_78 = auStack_a0;
  puStack_6c = auStack_a0;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  puStack_7c = auStack_20;
  uStack_74 = 8;
  uStack_68 = 8;
  uStack_98 = param_3;
  uStack_94 = param_4;
  uStack_90 = param_5;
  uStack_8c = param_6;
  puStack_70 = puStack_7c;
  iVar1 = (*(code *)&LAB_4017b177_1)(auStack_64,0x40,param_2,puStack_7c,auStack_a0);
  if (-1 < iVar1) goto LAB_400f06fe;
LAB_400f06e8:
  param_1 = (int *)0x0;
LAB_400f06ea:
  param_2 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  iVar1 = func_0x40082ecc();
LAB_400f06fe:
  puVar2 = auStack_64;
  if (0x3f < iVar1) {
    puVar2 = (undefined1 *)func_0x40094d68(iVar1 + 1);
    if (puVar2 == (undefined1 *)0x0) goto LAB_400f06e8;
    iVar1 = (*(code *)&LAB_4017b177_1)(puVar2,iVar1 + 1,param_2,puStack_7c,puStack_78,uStack_74);
  }
  param_1 = (int *)(**(code **)(*param_1 + 0xc))(param_1,puVar2,iVar1);
  if (puVar2 != auStack_64) {
    func_0x40094d88(puVar2);
  }
  goto LAB_400f06ea;
}

