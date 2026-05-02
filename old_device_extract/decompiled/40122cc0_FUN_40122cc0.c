// Function : FUN_40122cc0
// Address  : 0x40122cc0
// Size     : 61 bytes


int FUN_40122cc0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_t0;
  
  uVar2 = *(uint *)(param_1 + 4);
  uVar4 = *(uint *)(param_1 + 8);
  iVar1 = uVar2 - uVar4;
  if (iVar1 < 1) {
    iVar1 = -iVar1;
  }
  iVar3 = (uVar2 < uVar4) * uVar2 + (uVar2 >= uVar4) * uVar4;
  if ((param_3 == (int *)0x0) || (param_2 == (int *)0x0)) {
    iVar3 = in_t0;
    (*(code *)&SUB_40094c54)("/xtensa/core_dump_port.c",0x158,"gs_dump","ite_elf");
  }
  *param_2 = iVar3;
  if (iVar3 + 0xe0000000U < 0x10000000) {
    iVar3 = 0x3ffbf6d0;
  }
  *param_3 = iVar3;
  memw();
  return iVar1;
}

