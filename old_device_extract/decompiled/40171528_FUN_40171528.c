// Function : FUN_40171528
// Address  : 0x40171528
// Size     : 142 bytes


byte FUN_40171528(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [40];
  
  iVar2 = (*(code *)&SUB_4008c01c)(param_1 + 9);
  pcVar6 = (char *)(param_1 + 9 + iVar2 + 1);
  if (3 < *(byte *)(param_1 + 8)) {
    if (*pcVar6 != '\x04') {
      return 0xff;
    }
    if (pcVar6[1] != '\0') {
      return 0xff;
    }
    pcVar6 = pcVar6 + 2;
  }
  if (*(char *)(param_1 + 9) == 'z') {
    uVar3 = FUN_4017127c(pcVar6,auStack_2c);
    iVar2 = FUN_401712a4(uVar3,auStack_30);
    if (*(char *)(param_1 + 8) == '\x01') {
      iVar2 = iVar2 + 1;
    }
    else {
      iVar2 = FUN_4017127c(iVar2,auStack_2c);
    }
    pbVar4 = (byte *)FUN_4017127c(iVar2,auStack_2c);
    for (pcVar6 = (char *)(param_1 + 10); cVar1 = *pcVar6, cVar1 != 'R'; pcVar6 = pcVar6 + 1) {
      if (cVar1 == 'P') {
        pbVar4 = (byte *)FUN_40171410(*pbVar4 & 0x7f,0,pbVar4 + 1,auStack_28);
      }
      else {
        if (cVar1 != 'L') goto LAB_40171559;
        pbVar4 = pbVar4 + 1;
      }
    }
    bVar5 = *pbVar4;
  }
  else {
LAB_40171559:
    bVar5 = 0;
  }
  return bVar5;
}

