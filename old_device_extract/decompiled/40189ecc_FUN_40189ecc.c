// Function : FUN_40189ecc
// Address  : 0x40189ecc
// Size     : 131 bytes


void FUN_40189ecc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1 == 0) || (iVar1 = 0, param_2 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x3da);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  for (; iVar1 < (int)(uint)*(ushort *)(param_2 + 0xe); iVar1 = iVar1 + 1) {
    piVar2 = (int *)(iVar1 * 4 + *(int *)(param_2 + 0x18));
    iVar3 = *piVar2;
    if (iVar3 != 0) {
      *piVar2 = 0;
      *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - (uint)*(ushort *)(iVar3 + 0x16);
      *(short *)(param_2 + 8) = *(short *)(param_2 + 8) + -1;
      memw();
      memw();
      FUN_40189de4(param_1);
      if (*(short *)(param_2 + 8) == 0) break;
    }
  }
  *(ushort *)(param_2 + 0xc) = *(short *)(param_2 + 0xc) + 1 + (short)iVar1 & 0xfff;
  memw();
  memw();
  return;
}

