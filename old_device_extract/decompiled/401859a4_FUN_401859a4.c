// Function : FUN_401859a4
// Address  : 0x401859a4
// Size     : 24 bytes


undefined4 FUN_401859a4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if ((iVar1 == 0) && (iVar1 = *(int *)(param_1 + 0x40), iVar1 == 0)) {
    return 0xffffffff;
  }
  return *(undefined4 *)(iVar1 + 0x68);
}

