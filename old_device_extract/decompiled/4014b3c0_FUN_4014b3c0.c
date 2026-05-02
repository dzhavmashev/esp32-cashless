// Function : FUN_4014b3c0
// Address  : 0x4014b3c0
// Size     : 111 bytes


void FUN_4014b3c0(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);
    uVar2 = (uint)(*(byte *)(iVar3 + 0x11) >> 4);
    if ((uVar2 < 8) &&
       ((puVar4 = *(uint **)(uVar2 * 4 + param_1 + 0x268), puVar4 != (uint *)0x0 &&
        ((*puVar4 & 4) != 0)))) {
      uVar1 = *(ushort *)(iVar3 + 0x12) >> 4;
      if ((uVar1 != (ushort)puVar4[3]) && ((uVar1 - (ushort)puVar4[3] & 0xfff) < 0x800)) {
        FUN_40189f58(param_1);
      }
    }
    return;
  }
  FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x595);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

