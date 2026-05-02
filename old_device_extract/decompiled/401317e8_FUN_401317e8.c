// Function : FUN_401317e8
// Address  : 0x401317e8
// Size     : 78 bytes


int FUN_401317e8(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  iVar1 = FUN_401315c4(param_1,(uint)((param_3 & 3) != 0) + (param_3 >> 2));
  uVar2 = 0;
  if (iVar1 == 0) {
    for (; uVar2 != param_3; uVar2 = uVar2 + 1) {
      puVar3 = (uint *)(*(int *)(param_1 + 8) + (uVar2 & 0xfffffffc));
      *puVar3 = *puVar3 | (uint)*(byte *)(param_2 + uVar2) << 0x20 - ((uVar2 & 3) * -8 + 0x20);
    }
    memw();
  }
  return iVar1;
}

