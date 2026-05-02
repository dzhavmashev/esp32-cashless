// Function : FUN_40155d28
// Address  : 0x40155d28
// Size     : 258 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40155d28(undefined4 param_1,int param_2,char param_3,undefined4 param_4,undefined4 param_5,
                 undefined1 param_6,undefined1 param_7)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  memw();
  puVar2 = (undefined4 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x60);
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  if ((_DAT_3ffc8864 != 0) && (*(int *)(param_2 + 0x54) != 0)) {
    if (*(int *)(param_2 + 0x6c) == 0) {
      if (_DAT_3ffc1a40 != 0) goto LAB_40155dce;
    }
    else if (_DAT_3ffc1a40 == 0) {
      memw();
      goto LAB_40155dce;
    }
    iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0x3e);
    puVar2[0xd] = iVar3;
    if (iVar3 == 0) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar2);
      return;
    }
    (*(code *)&SUB_4008b3d0)(iVar3,*(undefined4 *)(param_2 + 0x54),0x3e);
    if (*(int *)(param_2 + 0x68) != 0) {
      iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0xd);
      puVar2[0xe] = iVar3;
      if (iVar3 != 0) {
        memw();
        (*(code *)&SUB_4008b3d0)(iVar3,*(undefined4 *)(param_2 + 0x68),0xd);
      }
    }
  }
LAB_40155dce:
  uVar1 = *(undefined1 *)(param_2 + 0x70);
  *(undefined1 *)((int)puVar2 + 0x5d) = param_7;
  memw();
  *(undefined1 *)(puVar2 + 0xf) = uVar1;
  memw();
  memw();
  FUN_40155a54(puVar2,param_1,param_2,(int)param_3,param_4,param_5,param_6);
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  *puVar2 = 0;
  *_DAT_3ffc8924 = puVar2;
  _DAT_3ffc7a70 = _DAT_3ffc7a70 + 1;
  memw();
  memw();
  _DAT_3ffc8924 = puVar2;
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

