// Function : FUN_400fcddc
// Address  : 0x400fcddc
// Size     : 33 bytes


void FUN_400fcddc(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    (*(code *)&SUB_4000681c)(uVar3 >> 0xd & 1,iVar1,6);
    iVar1 = iVar2;
  } while (iVar2 != 0x45);
  return;
}

