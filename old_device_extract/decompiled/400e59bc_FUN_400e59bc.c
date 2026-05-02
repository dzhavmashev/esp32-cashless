// Function : FUN_400e59bc
// Address  : 0x400e59bc
// Size     : 268 bytes


int FUN_400e59bc(uint *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  FUN_400f06a4(0x3ffc5490,"aborted",param_2);
  if ((*param_1 & 0xfffffffd) == 0) {
    iVar4 = FUN_400e5650(param_1,param_3);
    if (iVar4 == 0) {
      uVar1 = FUN_400dc9cc(*param_4," an SSL message",param_4[1]);
      FUN_400e4768("t_state",uVar1);
    }
    else {
      FUN_400f0d18(param_1 + 0xf,param_1 + 0x17);
      *(undefined1 *)(param_1 + 0x80) = 0;
      FUN_400e4b9c(param_1,3);
      uVar1 = FUN_400dc9cc(*param_4," an SSL message",param_4[1]);
      FUN_400e4768("nd data",uVar1);
      uVar5 = param_4[1];
      uVar1 = FUN_400dc9cc(*param_4,"itiated",uVar5);
      FUN_40183db8(param_1 + 0xf,uVar1,uVar5);
      uVar5 = param_4[1];
      uVar1 = FUN_400dc9cc(*param_4,"started",uVar5);
      FUN_40183db8(param_1 + 0x1f,uVar1,uVar5);
      uVar2 = param_1[0x27];
      puVar3 = (uint *)FUN_400dc9cc(*param_4,"are_url",param_4[1]);
      if (puVar3 != (uint *)0x0) {
        *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
        *puVar3 = uVar2;
        puVar3[1] = 0;
      }
    }
  }
  else {
    uVar1 = FUN_400dc9cc(*param_4," an SSL message",param_4[1]);
    FUN_400e4768("nd: %s\n",uVar1);
    uVar2 = *param_1;
    puVar3 = (uint *)FUN_400dc9cc(*param_4,"t state",param_4[1]);
    iVar4 = 0;
    if (puVar3 != (uint *)0x0) {
      *puVar3 = uVar2;
      *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 10;
      puVar3[1] = (int)uVar2 >> 0x1f;
    }
  }
  return iVar4;
}

