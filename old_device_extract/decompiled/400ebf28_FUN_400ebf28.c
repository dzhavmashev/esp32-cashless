// Function : FUN_400ebf28
// Address  : 0x400ebf28
// Size     : 121 bytes


int FUN_400ebf28(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,char param_5,
                char param_6)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  
  **(undefined1 **)(param_1 + 4) = 0x30;
  if (param_6 != '\0') {
    **(byte **)(param_1 + 4) = **(byte **)(param_1 + 4) | 1;
  }
  iVar4 = 1;
  if (param_5 != '\0') {
    pbVar5 = *(byte **)(param_1 + 4);
    if (param_5 == '\x01') {
      bVar3 = *pbVar5;
      bVar6 = 2;
    }
    else {
      iVar4 = 0;
      if (param_5 != '\x02') goto LAB_400ebf62;
      bVar3 = *pbVar5;
      bVar6 = 4;
    }
    *pbVar5 = bVar3 | bVar6;
    iVar4 = 1;
  }
LAB_400ebf62:
  iVar1 = FUN_401845b0(param_4,*(int *)(param_1 + 4) + iVar4);
  iVar2 = FUN_400ec628(param_3,*(int *)(param_1 + 4) + iVar1 + iVar4);
  iVar2 = iVar1 + iVar4 + iVar2;
  if (param_5 != '\0') {
    *(char *)(*(int *)(param_1 + 4) + iVar2) = (char)((param_2 & 0xffff) >> 8);
    iVar4 = iVar2 + 1;
    iVar2 = iVar2 + 2;
    *(char *)(*(int *)(param_1 + 4) + iVar4) = (char)(param_2 & 0xffff);
  }
  return iVar2;
}

