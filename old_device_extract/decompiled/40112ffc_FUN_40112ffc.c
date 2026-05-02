// Function : FUN_40112ffc
// Address  : 0x40112ffc
// Size     : 53 bytes


void FUN_40112ffc(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_1 == 0) {
    iVar1 = (*(code *)&SUB_40094c54)("lid pcb",0x698,"mit_rto"," filled");
  }
  if (*(char *)(param_1 + 0x6e) != -1) {
    *(char *)(param_1 + 0x6e) = *(char *)(param_1 + 0x6e) + '\x01';
    memw();
  }
  memw();
  FUN_40112a70(iVar1);
  return;
}

