// Function : FUN_40189e44
// Address  : 0x40189e44
// Size     : 128 bytes


void FUN_40189e44(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = 1;
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x3c2);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  while ((int)uVar1 < (int)(uint)*(ushort *)(param_1 + 0xe)) {
    piVar2 = (int *)(uVar1 * 4 + *(int *)(param_1 + 0x18));
    iVar3 = *piVar2;
    if (iVar3 == 0) break;
    *piVar2 = 0;
    uVar1 = uVar1 + 1;
    *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) - (uint)*(ushort *)(iVar3 + 0x16);
    *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -1;
    memw();
    memw();
    FUN_40189de4(param_2);
  }
  FUN_401868c0(param_1,uVar1 & 0xff);
  *(ushort *)(param_1 + 0xc) = (short)uVar1 + *(short *)(param_1 + 0xc) & 0xfff;
  memw();
  memw();
  return;
}

