// Function : FUN_4013d714
// Address  : 0x4013d714
// Size     : 99 bytes


int FUN_4013d714(undefined4 param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  uint uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  
  uVar2 = param_4 >> 1;
  iStack_30 = param_3[2];
  iStack_28 = param_4 - uVar2;
  uStack_38 = *param_3;
  iStack_24 = iStack_30 + uVar2 * 4;
  memw();
  uStack_34 = uVar2;
  uStack_2c = uStack_38;
  FUN_40186008(auStack_44);
  iVar1 = FUN_4013d5d8(auStack_44,param_2,&uStack_38);
  if (((iVar1 == 0) && (iVar1 = FUN_4013d5d8(param_1,param_2,&uStack_2c), iVar1 == 0)) &&
     (iVar1 = FUN_40131980(param_1,uVar2 << 5), iVar1 == 0)) {
    iVar1 = FUN_40131d18(param_1,param_1,auStack_44);
  }
  FUN_40131548(auStack_44);
  return iVar1;
}

