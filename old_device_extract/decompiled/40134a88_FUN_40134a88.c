// Function : FUN_40134a88
// Address  : 0x40134a88
// Size     : 372 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40134a88(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,
                 undefined4 param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_194;
  undefined1 auStack_17c [12];
  undefined1 auStack_170 [100];
  undefined1 auStack_10c [100];
  undefined1 auStack_a8 [132];
  int iStack_24;
  
  memw();
  uVar3 = param_1[0x17] + 7U >> 3;
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40138f28(param_7);
  iVar2 = -0x4f80;
  if (iVar1 == 0) goto LAB_40134b75;
  FUN_40186008(auStack_17c);
  FUN_40138c04(auStack_170);
  iVar2 = FUN_40131900(param_4,auStack_a8,uVar3);
  if (((iVar2 == 0) && (iVar2 = FUN_40134788(param_1,auStack_17c,param_5,param_6), iVar2 == 0)) &&
     (iVar2 = FUN_40131900(auStack_17c,auStack_a8 + uVar3,uVar3), iVar2 == 0)) {
    iStack_194 = uVar3 << 1;
    memw();
    iVar2 = FUN_40138df0(auStack_170,iVar1,auStack_a8,iStack_194);
    if (iVar2 == 0) {
      if (param_8 == 0) goto LAB_40134b91;
      iVar2 = -0x4f80;
      if ((*param_1 != 9) && (param_1[0x15] != 0)) {
        memw();
        iVar2 = FUN_401347dc(param_1,param_2,param_3,param_4,param_5,param_6,0x40138ef8,auStack_170,
                             param_8,param_9);
      }
    }
  }
  while( true ) {
    FUN_40138f14(auStack_170);
    FUN_40131548(auStack_17c);
LAB_40134b75:
    iVar1 = iVar2;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
LAB_40134b91:
    FUN_40138c04(auStack_10c);
    FUN_40138df0(auStack_10c,iVar1,auStack_a8,iStack_194);
    iVar2 = FUN_40138c20(auStack_10c,&DAT_3f41df54,0x10);
    if (((iVar2 == 0) && (iVar2 = -0x4f80, *param_1 != 9)) && (param_1[0x15] != 0)) {
      memw();
      iVar2 = FUN_401347dc(param_1,param_2,param_3,param_4,param_5,param_6,0x40138ef8,auStack_170,
                           0x40138ef8,auStack_10c);
    }
    FUN_40138f14(auStack_10c);
  }
  return;
}

