// Function : FUN_40134d24
// Address  : 0x40134d24
// Size     : 129 bytes


void FUN_40134d24(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int local_40;
  int iStack_3c;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  memw();
  local_40 = param_4;
  FUN_40186008(auStack_38);
  FUN_40186008(auStack_2c);
  param_4 = param_4 + param_5;
  iVar1 = FUN_40141738(&local_40,param_4,&iStack_3c,0x30);
  if ((((iVar1 == 0) && (param_4 == local_40 + iStack_3c)) &&
      (iVar1 = FUN_40141824(&local_40,param_4,auStack_38), iVar1 == 0)) &&
     (iVar1 = FUN_40141824(&local_40,param_4,auStack_2c), iVar1 == 0)) {
    FUN_40134958(param_1,param_2,param_3,param_1 + 0x88,auStack_38,auStack_2c);
  }
  FUN_40131548(auStack_38);
  FUN_40131548(auStack_2c);
  return;
}

