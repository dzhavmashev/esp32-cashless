// Function : FUN_4015c820
// Address  : 0x4015c820
// Size     : 55 bytes


int FUN_4015c820(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = &DAT_3ffc91f8;
  uVar4 = (uint)DAT_3ffca0b6;
  while( true ) {
    if (puVar2 == &DAT_3ffc91f8 + uVar4 * 4) {
      return 0;
    }
    iVar3 = *(int *)(puVar2 + 0xea8);
    if ((iVar3 != 0) && (iVar1 = (*(code *)&SUB_4008b33c)(iVar3 + 4,param_1,6), iVar1 == 0)) break;
    puVar2 = puVar2 + 4;
  }
  return iVar3;
}

