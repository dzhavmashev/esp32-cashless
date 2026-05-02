// Function : FUN_40100a84
// Address  : 0x40100a84
// Size     : 54 bytes


undefined4 FUN_40100a84(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4011b0cc(0);
  if (iVar1 == 0) {
    FUN_4011ade8(&DAT_3ffc585c,0);
    FUN_40109e04(&LAB_40100768,param_1,&DAT_3ffc5860);
    FUN_4011ad9c(&DAT_3ffc585c);
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  else {
    uVar2 = (**(code **)(param_1 + 8))(param_1);
  }
  return uVar2;
}

