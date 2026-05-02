// Function : FUN_4015dcd0
// Address  : 0x4015dcd0
// Size     : 198 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015dcd0(char param_1,int *param_2)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  char local_50;
  undefined1 uStack_4f;
  int *piStack_4c;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  int iStack_44;
  int iStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  int *piStack_30;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (*param_2 == 0) {
    return;
  }
  piStack_30 = param_2 + 1;
  uVar2 = (undefined1)*(undefined2 *)((int)param_2 + 0x26);
  bVar1 = *(int *)(*param_2 + 0x14c) != 0;
  uVar4 = 0;
  if (bVar1) {
    uVar4 = uVar2;
  }
  memw();
  uVar3 = FUN_401544a4(param_2);
  (*(code *)&SUB_4008b530)(&local_50,0,0x18);
  memw();
  iStack_44 = (int)(char)param_2[0x29];
  iStack_40 = (int)param_2 + 0x83;
  memw();
  uStack_3a = *(undefined1 *)((int)param_2 + 0x15e);
  uStack_3c = *(undefined1 *)((int)param_2 + 0x2ef);
  uStack_3b = *(undefined1 *)((int)param_2 + 0x2f3);
  piStack_4c = piStack_30;
  memw();
  memw();
  local_50 = param_1;
  uStack_4f = bVar1;
  uStack_48 = uVar4;
  uStack_47 = uVar2;
  uStack_46 = uVar3;
  FUN_4015fe44(&local_50);
  if (!bVar1) {
    return;
  }
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  if (param_1 == '\0') {
    if (DAT_3ffc89d6 == '\0') goto LAB_4015dd86;
    DAT_3ffc89d6 = DAT_3ffc89d6 + -1;
  }
  else {
    DAT_3ffc89d6 = DAT_3ffc89d6 + '\x01';
  }
  memw();
LAB_4015dd86:
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

