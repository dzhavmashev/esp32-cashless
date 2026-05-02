// Function : FUN_40162ea4
// Address  : 0x40162ea4
// Size     : 129 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40162ea4(int param_1,int param_2,char param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = *(uint **)(*(int *)(param_4 + 4) + 4);
  uVar1 = (*(code *)&SUB_4000ab7c)(*puVar3 & 0xfff,4);
  uVar2 = (uVar1 & 0xffff) + param_2;
  uVar4 = *(uint *)(*(int *)(param_4 + 0x2c) + 0x10) >> 0x14 & 0xf;
  if (*(ushort *)(param_1 + 0x7a) < uVar2) {
    *(undefined1 *)(_DAT_3ffc0034 + uVar4 * 0x30 + 0x4c) = 1;
    memw();
    if (param_5 == 0) goto LAB_40162ef1;
  }
  if ((uVar2 <= *(ushort *)(param_1 + 0x7c)) &&
     ((byte)(*(char *)((int)puVar3 + 3) - param_3) < *(byte *)(_DAT_3ffc0034 + uVar4 * 0x30 + 0x2f))
     ) {
    return ((*puVar3 >> 0xc & 0x7f) + 1) * 4 + uVar1 & 0xffff;
  }
LAB_40162ef1:
  memw();
  return 0;
}

