// Function : FUN_40154c6c
// Address  : 0x40154c6c
// Size     : 229 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40154c6c(int param_1,char param_2,char param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = _DAT_3ffc8800;
  iVar3 = _DAT_3ffc8800 + 0x9c;
  *(int *)(_DAT_3ffc8800 + 0xe4) = param_1;
  memw();
  (*(code *)&SUB_4008b3d0)(iVar3,param_1 + 4,6);
  FUN_40147fe4(1,4,4,0x3f43387e,param_3,param_2);
  uVar5 = 0xb0;
  uVar4 = 2;
  if (param_3 == '\0') {
    uVar5 = 0x20;
    if (param_2 == '\0') {
      uVar5 = 0;
    }
    uVar4 = 3;
  }
  FUN_40157594(&DAT_3ffc87f0,uVar4,uVar5);
  FUN_40147fe4(1,4,4,0x3f43386a);
  iVar1 = iVar1 + 4;
  (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar1);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar1);
  (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar1,&LAB_4015c248,0);
  if (DAT_3ffc89ec == '\x06') {
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0xe8);
    uVar5 = 4000;
  }
  else {
    if ((_DAT_3ffc8864 != 0) && (memw(), DAT_3ffc1a3c == '\0')) {
      memw();
      uVar5 = 0x4b0;
      if (_DAT_3ffc1a40 != 0) {
        uVar5 = 0x5dc;
      }
      (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar1,uVar5,0);
      return;
    }
    uVar5 = 1000;
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0xe8);
  }
  (*pcVar2)(iVar1,uVar5,0);
  return;
}

