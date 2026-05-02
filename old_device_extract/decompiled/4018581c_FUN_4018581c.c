// Function : FUN_4018581c
// Address  : 0x4018581c
// Size     : 36 bytes


int FUN_4018581c(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(code **)(param_1 + 0x60) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x60))(*(undefined4 *)(param_1 + 0x58));
    iVar1 = -(uint)(iVar1 == 2);
  }
  return iVar1;
}

