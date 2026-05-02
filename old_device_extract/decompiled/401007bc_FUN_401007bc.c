// Function : FUN_401007bc
// Address  : 0x401007bc
// Size     : 42 bytes


undefined4 FUN_401007bc(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    uVar1 = 0x103;
  }
  else {
    (*(code *)&SUB_4008b3d0)
              (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc),*(int *)(param_1 + 0x10),0xc);
    uVar1 = 0;
  }
  return uVar1;
}

