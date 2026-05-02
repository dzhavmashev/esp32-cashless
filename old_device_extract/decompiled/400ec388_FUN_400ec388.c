// Function : FUN_400ec388
// Address  : 0x400ec388
// Size     : 69 bytes


undefined4 FUN_400ec388(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  cVar1 = *(char *)(*param_1 + param_1[2]);
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  *(char *)((int)param_1 + 0x15) = cVar1;
  *(undefined1 *)(param_1 + 6) = 0;
  if (cVar1 == '\x02') {
    if ((*(byte *)(param_1 + 5) & 0xf0) == 0x20) {
      puVar3 = (undefined1 *)0x400ec210;
    }
    else {
      puVar3 = &LAB_400ec258;
    }
    param_1[4] = (int)puVar3;
    uVar2 = 0;
  }
  else {
    param_1[4] = (int)&LAB_400ec520;
    uVar2 = 2;
  }
  return uVar2;
}

