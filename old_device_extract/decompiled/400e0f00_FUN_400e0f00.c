// Function : FUN_400e0f00
// Address  : 0x400e0f00
// Size     : 113 bytes


undefined8 FUN_400e0f00(undefined8 *param_1)

{
  byte bVar1;
  undefined8 uVar2;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  
  bVar1 = *(byte *)(param_1 + 1) & 0x7f;
  if (bVar1 == 6) {
    uVar2 = (*(code *)&SUB_4000c938)(*(undefined1 *)param_1);
  }
  else if (bVar1 < 7) {
    uVar2 = 0;
    if (3 < bVar1) {
      uStack_28 = 0;
      FUN_400d3f78(*(undefined4 *)param_1,auStack_30);
      uVar2 = FUN_400e0f00(auStack_30);
    }
  }
  else if (bVar1 == 10) {
    uVar2 = (*(code *)&SUB_4000c988)(*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4));
  }
  else if (bVar1 == 0xc) {
    uVar2 = *param_1;
  }
  else {
    uVar2 = 0;
    if (bVar1 == 8) {
      uVar2 = (*(code *)&SUB_4000c978)(*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4));
    }
  }
  return uVar2;
}

