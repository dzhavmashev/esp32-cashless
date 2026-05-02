// Function : FUN_40158990
// Address  : 0x40158990
// Size     : 106 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40158990(void)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(_DAT_3ffc8800 + 0xe4) != 0) {
    iVar2 = _DAT_3ffc8800 + 0x54;
    iVar1 = _DAT_3ffc8800 + 4;
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar2);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar2);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar1);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar1);
    (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar1,&LAB_4015c248,0);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar1,1000,0);
    FUN_40157594(&DAT_3ffc87f0,3,0);
  }
  return;
}

