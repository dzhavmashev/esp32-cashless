// Function : FUN_4018b8d8
// Address  : 0x4018b8d8
// Size     : 74 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018b8d8(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_3ffc8800;
  if ((((_DAT_3ffc8800 != 0) && (*(int *)(_DAT_3ffc8800 + 0xe4) != 0)) &&
      (*(int *)(_DAT_3ffc8800 + 0x98) == 5)) && (*(char *)(_DAT_3ffc8800 + 0x94) == '\0')) {
    iVar2 = _DAT_3ffc8800 + 0x18;
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar2);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar2,(uint)*(ushort *)(iVar1 + 0x23a) * 1000,0);
  }
  return;
}

