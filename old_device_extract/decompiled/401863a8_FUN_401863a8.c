// Function : FUN_401863a8
// Address  : 0x401863a8
// Size     : 48 bytes


void FUN_401863a8(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  iVar1 = 0;
  while (iVar1 != param_1 << 2) {
    puVar3 = (uint *)(param_2 + iVar1);
    puVar2 = (uint *)(param_3 + iVar1);
    iVar1 = iVar1 + 4;
    *puVar3 = -(param_4 & 0xff) & *puVar2 | (param_4 & 0xff) - 1 & *puVar3;
    memw();
  }
  return;
}

