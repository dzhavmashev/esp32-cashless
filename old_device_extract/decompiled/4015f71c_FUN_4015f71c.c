// Function : FUN_4015f71c
// Address  : 0x4015f71c
// Size     : 145 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015f71c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  if (9 < param_1) {
    return;
  }
  iVar3 = param_1 * 0x14;
  *(undefined2 *)(iVar3 + 0x3ffbff26) = 0;
  memw();
  while( true ) {
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    iVar1 = _DAT_3ffc1a34;
    if (*(int *)(iVar3 + 0x3ffbff18) == 0) break;
    iVar4 = *(int *)(iVar3 + 0x3ffbff18);
    *(int *)(iVar3 + 0x3ffbff18) = *(int *)(iVar4 + 0x28);
    uVar2 = _DAT_3ffc799c;
    pcVar5 = *(code **)(iVar1 + 0x58);
    *(undefined4 *)(iVar4 + 0x28) = 0;
    memw();
    (*pcVar5)(uVar2);
    if (param_1 == 5) {
      (*(code *)&SUB_4008b530)(*(undefined4 *)(iVar4 + 0x2c),0,0x20);
      (*(code *)&SUB_4008b530)(iVar4,0,0x30);
    }
    else {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar4);
    }
  }
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

