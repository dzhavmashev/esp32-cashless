// Function : FUN_4015e03c
// Address  : 0x4015e03c
// Size     : 333 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015e03c(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  FUN_4015dcd0(1,param_2);
  iVar2 = param_1 + 0x18;
  (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar2);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar2);
  (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar2,0x4015b918,0);
  iVar1 = param_1 + 4;
  (**(code **)(_DAT_3ffc1a34 + 0xe8))
            (iVar2,(uint)*(ushort *)(*(int *)(param_1 + 0xe4) + 0x28) *
                   (uint)*(ushort *)(param_1 + 0x23a) * 10,0);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar1);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar1);
  (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar1,0x4015b8e8,0);
  if ((*(int *)(_DAT_3ffca40c + 4) == 0) || (*(int *)(_DAT_3ffca40c + 8) != 2)) {
    if ((0xd < DAT_3ffc89ed) || ((0x2410U >> (DAT_3ffc89ed & 0x1f) & 1) != 1)) {
      FUN_40147fe4(1,4,4,0x3f4343dc);
      (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar1,10000,0);
      return;
    }
    if (_DAT_3ffc89a8 == 0) {
      return;
    }
    if (*(code **)(_DAT_3ffc89a8 + 0xc) == (code *)0x0) {
      return;
    }
    iVar2 = (**(code **)(_DAT_3ffc89a8 + 0xc))();
    if (iVar2 != 0) {
      FUN_40147fe4(1,4,4,0x3f434434);
      (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar1,1000,0);
      return;
    }
    FUN_40147fe4(1,4,4,0x3f434408);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar1,30000,0);
    if (_DAT_3ffc89a8 == 0) {
      return;
    }
    pcVar3 = *(code **)(_DAT_3ffc89a8 + 4);
  }
  else {
    FUN_40147fe4(1,4,4,0x3f43445f);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar1,20000,0);
    if (_DAT_3ffc89ac == 0) {
      return;
    }
    pcVar3 = *(code **)(_DAT_3ffc89ac + 0xc);
  }
  if (pcVar3 == (code *)0x0) {
    return;
  }
  (*pcVar3)();
  return;
}

