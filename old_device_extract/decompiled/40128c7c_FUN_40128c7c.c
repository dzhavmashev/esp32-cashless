// Function : FUN_40128c7c
// Address  : 0x40128c7c
// Size     : 123 bytes


void FUN_40128c7c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_38);
  FUN_40186008(auStack_2c);
  iVar1 = FUN_40131d74(auStack_38,param_2,1);
  if ((((iVar1 == 0) && (iVar1 = FUN_40131a34(auStack_38,1), iVar1 == 0)) &&
      (iVar1 = FUN_4013d3d8(auStack_2c,param_1,auStack_38,param_2,0), iVar1 == 0)) &&
     ((iVar1 = FUN_40131ad8(auStack_2c,1), iVar1 != 0 &&
      (iVar1 = FUN_40131ad8(auStack_2c,0), iVar1 != 0)))) {
    FUN_401860ec(auStack_2c,param_2);
  }
  FUN_40131548(auStack_2c);
  FUN_40131548(auStack_38);
  return;
}

