// Function : FUN_4010c094
// Address  : 0x4010c094
// Size     : 116 bytes


undefined1 FUN_4010c094(undefined4 param_1,int param_2,uint param_3,undefined2 param_4)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint in_t0;
  ushort auStack_22 [17];
  
  puVar2 = (undefined4 *)(*(code *)&LAB_4018533b_1)(param_1,param_4,auStack_22);
  param_3 = param_3 & 0xffff;
  if ((puVar2 == (undefined4 *)0x0) ||
     (uVar3 = (uint)auStack_22[0], (uint)*(ushort *)(puVar2 + 2) < uVar3 + param_3)) {
    uVar1 = 0xff;
  }
  else {
    uVar5 = (uint)*(ushort *)((int)puVar2 + 10);
    if (uVar5 <= uVar3) {
      uVar5 = in_t0;
      (*(code *)&SUB_40094c54)("if_init",0x50e,"f_clone","ll data");
    }
    uVar4 = param_3;
    if ((int)(uVar5 - uVar3) < (int)param_3) {
      uVar4 = uVar5 - uVar3 & 0xffff;
    }
    (*(code *)&SUB_4008b3d0)(puVar2[1] + uVar3,param_2,uVar4);
    uVar1 = 0;
    if ((param_3 - uVar4 & 0xffff) != 0) {
      uVar1 = FUN_4010c020(*puVar2,param_2 + uVar4);
    }
  }
  return uVar1;
}

