// Function : FUN_40165df0
// Address  : 0x40165df0
// Size     : 42 bytes


void FUN_40165df0(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(&DAT_3ffc0718 + (param_1 & 0xff) * 4);
  iVar2 = 0;
  do {
    if (((param_2 ^ 0xffffffff) & uVar1 & 1 << ((byte)iVar2 & 0x1f)) != 0) {
      FUN_40165db8(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x19);
  return;
}

