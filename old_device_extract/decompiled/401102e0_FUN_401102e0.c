// Function : FUN_401102e0
// Address  : 0x401102e0
// Size     : 77 bytes


int FUN_401102e0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x742,"epalive","lid seg");
  }
  memw();
  iVar1 = FUN_401100f0(*(undefined4 *)(param_1 + 0x50),0);
  if (iVar1 != 0) {
    *(uint *)(param_1 + 0x58) = *(int *)(param_1 + 0x50) + (uint)*(ushort *)(param_1 + 0x56);
  }
  memw();
  return iVar1;
}

