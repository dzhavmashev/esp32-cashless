// Function : FUN_4015b284
// Address  : 0x4015b284
// Size     : 226 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b284(char *param_1)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if ((param_1 == (char *)0x0) || (0xd < (byte)(*param_1 - 1U))) {
    pcVar4 = "el info";
LAB_4015b2a9:
    FUN_40147fe4(1,8,1,pcVar4);
    return;
  }
  iVar1 = FUN_4015b24c();
  if (iVar1 == 0) {
    pcVar4 = "";
    goto LAB_4015b2a9;
  }
  sVar2 = *(short *)(iVar1 + 2);
  FUN_40160000(param_1);
  if (param_1[1] == '\x02') {
    if ((byte)(*param_1 - 5U) < 9) {
      sVar2 = sVar2 + -10;
      FUN_40147fe4(1,8,5,0x3f43621f,sVar2);
      uVar3 = 3;
      goto LAB_4015b330;
    }
  }
  else if ((param_1[1] == '\x01') && ((byte)(*param_1 - 1U) < 9)) {
    sVar2 = sVar2 + 10;
    FUN_40147fe4(1,8,5,0x3f436208,sVar2);
    uVar3 = 2;
    goto LAB_4015b330;
  }
  FUN_40147fe4(1,8,5,0x3f4361f2,sVar2);
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 4))();
  uVar3 = 0;
  if (iVar1 == 0) {
    uVar3 = 1;
  }
LAB_4015b330:
  FUN_4015b020(sVar2,uVar3);
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  iVar1 = _DAT_3ffbfdf0;
  *(char *)(_DAT_3ffbfdf0 + 0x52) = *param_1;
  memw();
  *(char *)(iVar1 + 0x53) = param_1[1];
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

