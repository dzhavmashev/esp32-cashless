// Function : FUN_401583bc
// Address  : 0x401583bc
// Size     : 300 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401583bc(int *param_1)

{
  int iVar1;
  code *pcVar2;
  short in_a6;
  uint in_a7;
  int iVar3;
  
  in_a7 = in_a7 & 0xffff;
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0x98) != 2) {
    FUN_40147fe4(1,4,4,0x3f433e1f);
    return;
  }
  if (in_a6 == 2) {
    if (in_a7 == 0xd) {
      DAT_3ffc89ec = 2;
      memw();
      memw();
      FUN_40147fe4(1,4,4,0x3f433dd9,0xd);
      FUN_40153ed0(*(undefined4 *)(iVar1 + 0xe4),0xb0,1);
      return;
    }
    if (in_a7 != 0) {
      FUN_40147fe4(1,4,4,0x3f433db6,in_a7);
      iVar3 = in_a7 << 8;
      goto LAB_40158444;
    }
    FUN_40157594(&DAT_3ffc87f0,3,0);
    FUN_40147fe4(1,4,4,0x3f433d93);
    iVar3 = iVar1 + 4;
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar3);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar3);
    (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar3,0x4015c258,0);
    if ((_DAT_3ffc8864 != 0) && (memw(), DAT_3ffc1a3c == '\0')) {
      pcVar2 = *(code **)(_DAT_3ffc1a34 + 0xe8);
      goto LAB_401584e1;
    }
  }
  else {
    FUN_40147fe4(1,4,4,0x3f433e10);
    iVar3 = 0;
LAB_40158444:
    FUN_40157594(&DAT_3ffc87f0,0,iVar3);
    iVar3 = FUN_40186978();
    if (iVar3 == 0) {
      return;
    }
    iVar3 = iVar1 + 4;
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar3);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar3);
    (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar3,0x4015b8d8,0);
  }
  pcVar2 = *(code **)(_DAT_3ffc1a34 + 0xe8);
LAB_401584e1:
  (*pcVar2)(iVar1 + 4,1000,0);
  return;
}

