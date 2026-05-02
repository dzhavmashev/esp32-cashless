// Function : FUN_4017435c
// Address  : 0x4017435c
// Size     : 7 bytes


undefined4
FUN_4017435c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_a8;
  int in_a13;
  undefined4 in_a15;
  int in_SAR;
  
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(in_a13 + iVar1 + 0x88) = param_3;
  *(undefined4 *)(in_a13 + iVar1 + 0x14) = unaff_a8;
  *(undefined4 *)(in_a13 + iVar1 + 8) = unaff_a8;
  *(undefined4 *)(in_a13 + iVar1 + 0xc) = 0xffff0208;
  *(int *)(in_a13 + iVar1 + 0x68) = in_a13 + iVar1 + 0xa0;
  *(int *)(in_a13 + iVar1 + 0x6c) = in_a13 + iVar1 + 0x80;
  *(undefined4 *)(in_a13 + iVar1 + 0x70) = 8;
  *(undefined4 *)(in_a13 + iVar1 + 0x8c) = param_4;
  *(undefined4 *)(in_a13 + iVar1 + 0x90) = param_5;
  *(undefined4 *)(in_a13 + iVar1 + 0x94) = param_6;
  uVar2 = (*(code *)&SUB_4009164c)();
  uVar2 = FUN_40174c80(uVar2,in_a13 + iVar1,(int)(CONCAT44(param_5,in_a15) >> in_SAR),
                       *(undefined4 *)(in_a13 + iVar1 + 0x68),*(undefined4 *)(in_a13 + iVar1 + 0x6c)
                       ,*(undefined4 *)(in_a13 + iVar1 + 0x70));
  **(undefined1 **)(in_a13 + iVar1) = 0;
  return uVar2;
}

